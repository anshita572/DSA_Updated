const path=require('path')
const express=require('express')
const app=express()

app.set('view engine','hbs')  //to set handlebars after installing it for dynamic sites
// console.log(__dirname) //displays path till current directory
// console.log(__filename) //displays path till current file
// console.log(path.join(__dirname,'../public'))



// app.get('',(req,res)=>{
//     res.send("<h1>hi</h1>")
// })
app.get('',(req,res)=>{
    res.render('index',{
        title : 'using hbs from app.js',
        myName: 'Akshu'
    }) //render is used for views handlebars
})
const directoryPath=path.join(__dirname,'../public')
app.use(express.static(directoryPath)) //for index.html in public folder
// app.get('/about',(req,res)=>{
//     res.send([{
//         myName :'Anshita',
//         age : 20
//     },
// {
//     myName : 'Reena',
//     age:20
// }])
// })
app.listen(3000,()=>{
    console.log("Server is running on port 3000")
})