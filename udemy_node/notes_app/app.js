const yargs=require('yargs')
const chalk=require('chalk')
console.log(chalk.bold('Hey there'))
console.log(process.argv)
console.log(yargs.argv)
// const command=process.argv[2]
// if(command==='add')
// {console.log("Adding notes ! ")}
// else if(command==='remove')
// {console.log("Removing notes ! ")}