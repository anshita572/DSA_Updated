import { Fragment } from "react";
import { MouseEvent } from "react";
function ListGroup(){
  let items=["Patiala","Ludhiana","Delhi","Mumbai"]
  //event handler
  const handleClick=(event : MouseEvent)=>console.log(event);
  // items=[];
    return (
        <>
    <h1>List</h1>
    {/* {items.length===0 ? <p>No item found</p> : null} */}
    {items.length===0 && <p>No item found</p>}  
    {/* if no item then say no item found */}
    <ul className="list-group">
    {items.map((i,index)=>(
      <li className="list-group-item"
       key={i}
      //  onClick={()=>console.log(i,index)}
      onClick={handleClick}
       >
      
        {i}</li>
    ))}
  </ul>
  </>
    ); //items.map((i) => loop
}
export default ListGroup;