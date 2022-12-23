const fs=require('fs')
fs.writeFileSync('intro.txt','hi everyone')
fs.appendFileSync('intro.txt',' welcome home')
