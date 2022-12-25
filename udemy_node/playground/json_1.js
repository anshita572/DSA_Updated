const fs=require("fs")
const book={
    title : "Inspire",
    author : "Fiago"
}
const bookJson=JSON.stringify(book)
// console.log(bookJson)
// console.log(bookJson.title) //error
const bookParse=JSON.parse(bookJson)
// console.log(bookParse.title)
// fs.writeFileSync('json_1.json',bookJson)
const dataBuffer=fs.readFileSync('json_1.json')
// console.log(dataBuffer)
const dataJSON=dataBuffer.toString()
// console.log(dataJSON)
const data=JSON.parse(dataJSON)
console.log(data.title)
data.title="Ego"
data.author="Jessi"
const newData=JSON.stringify(data)
fs.writeFileSync('json_1.json',newData)