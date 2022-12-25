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
    handler:function()   //main thing what is going to happen when this command is used
    {console.log('Adding a new note')}
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