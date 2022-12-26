const fs=require('fs')
const getNotes=function()
{return "Your notes..."}
const addNote=function(title,body){
    const notes=loadNotes()
    // console.log(notes)
    const duplicateNotes=notes.filter(function(note){ //to avoid taking duplicate notes
        // return note.title===title
        if(note.title===title)
        {return true}
    })
    if(duplicateNotes.length===0) //if no duplicate note
    {notes.push({
        title:title,
        body:body   
    })
    saveNotes(notes)
console.log("New note taken ! ")}
else{
    console.log("Note has already been taken !")
}
    
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
    getNotes:getNotes,
    addNote:addNote
} //to export multiple functions