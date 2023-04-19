import React,{Suspense}from 'react'
import { Canvas } from '@react-three/fiber';
import { OrbitControls,Preload,useGLTF } from '@react-three/drei';
import CanvasLoader from '../Loader';


const Earth = () => {
  // to import that 3d earth-model
  const earth=useGLTF('./planet/scene.gltf')
  return (
   <primitive
   object={earth.scene}
   scale={2.5} 
   //scale means size of earth model
   position-y={0}
   rotation-y={0}
   />
  )
}
const EarthCanvas=()=>{
  return(
    <Canvas
    shadows
    frameloop='demand'
    dpr={[1,2]}
    gl={{preserveDrawingBuffer:true}}
    camera={{
      fov:45,
      near:0.1,
      far:200,
      position:[-4,3,6]
    }}
    >
      <Suspense fallback={<CanvasLoader/>}>
      {/* suspense is jab tak load nhi hoti show that loading percentage */}
      <OrbitControls
      autoRotate
      enableZoom={false}
      maxPolarAngle={Math.PI/2}
      minPolarAngle={Math.PI/2}
      />
      <Earth/>
      <Preload all/>
      </Suspense>
    </Canvas>
  )
}
export default EarthCanvas