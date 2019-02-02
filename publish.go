package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"os/exec"
	"strings"

	"github.com/ecutdavid/codeforcesreport"
)

var platforms = []string{"codeforces", "spoj", "codejam"}
var formalName = map[string]string{
	"codeforces": "Codeforces",
	"spoj":       "SPOJ",
	"codejam":    "Code Jam",
}

func getSolutionCountInDir(path string) (count int) {
	files, err := ioutil.ReadDir(path)
	if err != nil {
		log.Fatal(err)
	}
	for _, f := range files {
		if !f.IsDir() && (strings.HasSuffix(f.Name(), ".go") || strings.HasSuffix(f.Name(), ".cpp")) {
			count++
		}
		if f.IsDir() && !strings.HasSuffix(f.Name(), "-TBD") {
			count += getSolutionCountInDir(path + "/" + f.Name())
		}
	}
	return count
}

func getProgress() (result string) {
	for _, p := range platforms {
		count := getSolutionCountInDir("./" + p)
		if p == "codeforces" {
			res := codeforcesreport.FetchSubmissions("davidguandev")
			count = len(codeforcesreport.ParseUniqOkSubmissions(res))
		}
		if count > 1 {
			// add two spaces due to markdown
			result += fmt.Sprintf("%s: %d problems solved  \n", formalName[p], count)
		}
	}
	return result
}

func main() {
	readmeRaw, err := ioutil.ReadFile("./README.md")
	if err != nil {
		log.Fatal(err)
	}
	readme := strings.Split(string(readmeRaw), "\n")

	output := ""
	handlingProgress := false
	for i, line := range readme {
		if strings.HasPrefix(line, "## ") {
			if line == "## The Counter" {
				output += "## The Counter\n" + getProgress() + "\n"
				handlingProgress = true
			} else {
				handlingProgress = false
			}
		}
		if !handlingProgress {
			output += line
			if i != (len(readme) - 1) {
				output += "\n"
			}
		}
	}
	err = ioutil.WriteFile("./README.md", []byte(output), 0666)
	if err != nil {
		log.Fatal(err)
	}
	cmd := exec.Command("git", "add", "-A")
	cmd.Stdout = os.Stdout
	if err := cmd.Run(); err != nil {
		log.Fatal(err)
	}
	message := "automated commit from ./publish.go"
	if len(os.Args) > 1 {
		message = os.Args[1]
	}
	cmd = exec.Command("git", "commit", "-am", message)
	cmd.Stdout = os.Stdout
	if err = cmd.Run(); err != nil {
		log.Fatal(err)
	}
	cmd = exec.Command("git", "push")
	cmd.Stdout = os.Stdout
	if err = cmd.Run(); err != nil {
		log.Fatal(err)
	}
}
