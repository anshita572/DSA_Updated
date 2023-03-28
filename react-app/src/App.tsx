// import Message from './Message';
import ListGroup from "./components/ListGroup";
function App(){
  let items=["Patiala","Ludhiana","Delhi","Mumbai"]
  return <div><ListGroup items={items} heading={"Cities"}/></div>;
}
export default App;
