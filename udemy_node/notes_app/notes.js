const fs=require('fs')
const chalk=require('chalk')
const addNote=function(title,body){
    const notes=loadNotes()
    // console.log(notes)
    const duplicateNote=notes.find((note)=>note.title===title)
    if(!duplicateNote)
    {notes.push({
        title:title,
        body:body   
    })
    saveNotes(notes)
console.log(chalk.green.inverse("New note taken ! "))}
else{
    console.log(chalk.red.inverse("Note has already been taken !"))
}
    
}

    //OR (find se jahan duplicate mila vahin ruk k else wali statement will execute)(filter se agar ek duplicate mil gya toh bhi sbhi notes check honge i.e. sare duplicates find honge)=>find is more efficient
    
//     const duplicateNotes=notes.filter(function(note){ //to avoid taking duplicate notes
//         // return note.title===title
//         if(note.title===title)
//         {return true}
//     })//duplicate notes will have notes with titles that already exist
//     if(duplicateNotes.length===0) //if no duplicate note
//     {notes.push({
//         title:title,
//         body:body   
//     })
//     saveNotes(notes)
// console.log(chalk.green.inverse("New note taken ! "))}
// else{
//     console.log(chalk.red.inverse("Note has already been taken !"))
// }
    
//}
const removeNote=function(title)
{const notes=loadNotes()
const notesToKeep=notes.filter(function(note){
    // return note.title!==title
    if(note.title!==title)  //if the note title != title being passed in terminal,keep those notes
    {return true}
})
if(notes.length>notesToKeep.length)
{saveNotes(notesToKeep)
console.log(chalk.green.inverse("Note removed !"))}
else
{console.log(chalk.red.inverse("No note found !"))}}
const listNote=()=>{
    const notes=loadNotes()
    console.log(chalk.inverse('Your notes'))
    notes.forEach((i)=>{
        console.log(chalk.inverse.yellow(i.title))
    })
}
const readNote=(title)=>{
const notes=loadNotes()
const note=notes.find((note)=>note.title===title)
if(note)
{console.log(chalk.inverse(note.title))
console.log(chalk.inverse.yellow(note.body))}
else
{console.log(chalk.inverse.red('Note not found !'))}
}
const saveNotes=function(notes)
{
    const dataJSON=JSON.stringify(notes)
    fs.writeFileSync('notes.json',dataJSON)
}
const loadNotes=function(){
    try{
        const dataBuffer=fs.readFileSync('notes.json')
        const dataJSON=dataBuffer.toString()
        return JSON.parse(dataJSON)
    }
    catch(e)
    {return []}
}
module.exports={
    addNote:addNote,
    removeNote:removeNote,
    listNote:listNote,
    readNote:readNote
} //to export multiple functions