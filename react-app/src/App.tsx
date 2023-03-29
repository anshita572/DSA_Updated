// import Message from './Message';
import { useState } from "react";
import Alert from "./components/Alert";
import { Button } from "./components/Button";
import ListGroup from "./components/ListGroup";
function App(){
  //hook

  const[alertVisible,setAlertVisibility]=useState(false);
  
  // let items=["Patiala","Ludhiana","Delhi","Mumbai"]
  // const handleSelectItem=(item:string)=>{
  //   console.log(item);
  // }
  // return <div>
  //   <ListGroup items={items} heading={"Cities"} onSelectItem={handleSelectItem}/>
  //   </div>
    // return(
    //    <div> <Alert>Hi <span>Alert</span> </Alert></div>
    // );
    return(
      <div>
        {alertVisible && <Alert onClose={()=>setAlertVisibility
        (false)}>My alert</Alert>}
        <Button onClick={()=>setAlertVisibility(true)}>My button</Button>
      </div>
    )
}
export default App;
