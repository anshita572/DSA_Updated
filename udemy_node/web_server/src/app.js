const path=require('path')
const express=require('express')
const hbs=require('hbs')
// const { title } = require('process')
const app=express()

app.set('view engine','hbs')  //to set handlebars after installing it for dynamic sites
// console.log(__dirname) //displays path till current directory
// console.log(__filename) //displays path till current file
// console.log(path.join(__dirname,'../public'))



// app.get('',(req,res)=>{
//     res.send("<h1>hi</h1>")
// })
const viewPath=path.join(__dirname,'../templates/views')
app.set('views',viewPath)
const partialPath=path.join(__dirname,'../templates/partials')
hbs.registerPartials(partialPath)
//setup static directory to serve

app.get('',(req,res)=>{
    res.render('index',{
        title : 'using hbs from app.js',
        myName: 'Akshu'
    }) //render is used for views handlebars
})
app.get('/weather',(req,res)=>{
    if(!req.query.address)
    {return res.send({
        error:'You must provide an address'
    })}
    res.send({
        forecast:'It is sunny',
        location:'California',
        address:req.query.address
    })
})
app.get('/about',(req,res)=>{
    res.render('about',{
        mytitle:'about dogs',
        myName: 'Anshita'
    })
    
})
//Define paths for express config
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

// app.get('/about/*',(req,res)=>{
//     res.send('About article not found !')
// })

// app.get('*',(req,res)=>{
//     res.send('Oops ! Error 404')
// })
app.get('/about/*',(req,res)=>{
    res.render('404',{
        mytitle:'404',
        myName:'Anshita',
        errorMessage:'About article not found'
    })
})
app.get('*',(req,res)=>{
    res.render('404',{
        mytitle:'404',
        myName:'Anshita',
        errorMessage:'Oops ! Page not found'
    })
})
app.listen(3000,()=>{
    console.log("Server is running on port 3000")
})