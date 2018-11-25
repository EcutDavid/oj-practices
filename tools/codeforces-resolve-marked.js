document.querySelectorAll('.accepted-problem').forEach(d => {
  const problemName = `${d.children[0].innerText} ${d.children[1].innerText}`
  const url = `https://codeforces.com${d.children[1].querySelector('a').getAttribute('href')}`
  console.log(`* ![${problemName}](${url})`)
  const rm = d.querySelector('.remove-favourite')
  rm.click()
})