const yargs=require('yargs')
// const chalk=require('chalk')
// // console.log(chalk.bold('Hey there'))
// console.log(process.argv)
// console.log(yargs.argv)
// // const command=process.argv[2]
// // if(command==='add')
// // {console.log("Adding notes ! ")}
// // else if(command==='remove')
// // {console.log("Removing notes ! ")}
// yargs.version("1.1.0")
yargs.command({
    command:'add',   //name of command
    describe:'Adding a new note', //description (optional)
    builder:{
        title:{
            describe:'Note title',
            demandOption:true, //if I don't provide title in terminal ,it will give an error if demandOption is set to true (by default demandOption is false)
            type:'string' //if I don't specify the type as string ,by default it will take title as boolean type

        },
        body:{
            describe: 'Note body',
            demandOption:true,
            type:'string'
        }
    },
    handler:function(argv)   //main thing what is going to happen when this command is used
    {console.log('Title : '+argv.title)
    console.log('Body : '+argv.body)
}
})
yargs.command({
    command:'remove',
    describe:'Removing a note',
    handler:function()
    {console.log('Removing a note')}
})
yargs.command({
    command:'list',
    describe:'Listing a note',
    handler:function()
    {console.log('List a note')}
})
yargs.command({
    command:'read',
    describe:'Reading a note',

    handler:function()
    {console.log('Read a note')}
})
yargs.parse();
//or
// yargs.argv;