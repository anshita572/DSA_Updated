import {Suspense,useEffect,useState }from 'react';
import { Canvas } from '@react-three/fiber';
import {OrbitControls,Preload,useGLTF} from '@react-three/drei';

import CanvasLoader from '../Loader';

const Computers = ({isMobile}) => {
  const computer=useGLTF('./desktop_pc/scene.gltf')
  return (
    // in 3JS instead of div,we use mesh
    <mesh>
 {/* without light,we can't see anything ,so we use hemisphereLight */}
 <hemisphereLight intensity={0.15} groundColor="black"/>
 <pointLight intensity={1}/>
 <spotLight
 position={[-20,50,10]}
 angle={0.12}
 penumbra={1}
 intensity={1}
 castShadow
 shadow-mapSize={1024}
 />
 <primitive object={computer.scene} scale={isMobile ? 0.7 : 0.75} 
//  if on mobile then scale 0.7 else 0.75
 position={isMobile ? [0,-3,-2.2]:[0,-3.25,-1.5]}
 rotation={[-0.01,-0.2,-0.1]}
 />
    </mesh>
  )
}
const ComputersCanvas=()=>{

  // for mobile devices
  const[isMobile,setIsMobile]=useState(false);
  useEffect(()=>{
    // Adding an event listener for changes to the screen size
    const mediaQuery=window.matchMedia('max-width:500px)');
    // setting the initial value of 'isMobile' state variable
    setIsMobile(mediaQuery.matches);
    // define callback function to handle changes to media query
    const handleMediaQueryChange=(event)=>{
      setIsMobile(event.matches);
    };
    // add callback function as a listener for changes to media query
    mediaQuery.addEventListener
    ("change",handleMediaQueryChange);
    // remove the listener when component is unmounted
    return()=>{
    mediaQuery.removeEventListener("change",handleMediaQueryChange);
    }; 
  },[]);
  return(
    <Canvas
    frameloop='demand'
    shadows
    camera={{position:[20,3,5],fov:25}}
    gl={{preserveDrawingBuffer:true}}>
   <Suspense fallback={<CanvasLoader/>}>
    <OrbitControls
     enableZoom={false}
     maxPolarAngle={Math.PI/2}
     minPolarAngle={Math.PI/2}
    />
    {/* -180 to 180 degree hi ghum ske computer only utni direction m */}
    <Computers isMobile={isMobile}/>
   </Suspense>
   <Preload all/>
    </Canvas>
  )
}
export default ComputersCanvas;