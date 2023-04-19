import {Html,useProgress} from '@react-three/drei';
// it takes time to load 3d pc pic ,so we will show loading % upto 2 decimal places
const Loader = () => {
  const {progress}=useProgress();
  return (
    <Html>
      <span className='canvas-load'></span>
      <p style={{
        fontSize:14,
        color:"#f1f1f1",
        fontWeight:800,
        marginTop:40
        
      }}>{progress.toFixed(2)}%</p>  
      {/* loading % upto 2 decimal places */}
    </Html>
  )
}

export default Loader