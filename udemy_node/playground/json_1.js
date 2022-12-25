const fs=require("fs")
const book={
    title : "Inspire",
    author : "Fiago"
}
const bookJson=JSON.stringify(book)
console.log(bookJson)
// console.log(bookJson.title) //error
const bookParse=JSON.parse(bookJson)
console.log(bookParse.title)
fs.writeFileSync('json_1.json',bookJson)
