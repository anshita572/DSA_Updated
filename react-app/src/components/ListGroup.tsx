import { Fragment, useState } from "react";
// import { MouseEvent } from "react";
//{items : [],heading:string}
interface Props{
  items:string[];
  heading:string;
}
function ListGroup({items,heading}:Props){
  
  // let selectedIndex=0;
  //Hook
const[selectedIndex,setSelectedIndex]=useState(-1);
  // const arr=useState(-1);

  // arr[0] //variable(selectedIndex)
  // arr[1]//updater function

  //event handler
  // const handleClick=(event : MouseEvent)=>console.log(event);

  // items=[];
    return (
        <>
    <h1>{heading}</h1>
    {/* {items.length===0 ? <p>No item found</p> : null} */}
    {items.length===0 && <p>No item found</p>}  
    {/* if no item then say no item found */}
    <ul className="list-group">
    {items.map((i,index)=>( //items.map((i) => loop
      <li className={selectedIndex===index ? "list-group-item active" : "list-group-item"}
       key={i}
      //  onClick={()=>console.log(i,index)}
      // onClick={handleClick}
      onClick={()=>{setSelectedIndex(index);}}
       >
      
        {i}</li>
    ))}
  </ul>
  </>
    ); 
}
export default ListGroup;