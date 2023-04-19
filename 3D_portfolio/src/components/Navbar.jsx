import React,{useEffect,useState} from 'react'
import{ Link }from 'react-router-dom';
import {styles} from '../styles'
import {navLinks} from '../constants';
import{logo,menu,close} from '../assets';


const Navbar = () => {
  const [active, setActive] = useState(""); //when one of the nav tabs(about,contact..)is active
  const[toggle,setToggle]=useState(false); //for mobile devices
//   In React.js, useState is a hook function that allows you to add state to functional components.
// The code const[toggle,setToggle]=useState(false) declares a new state variable called toggle and a function called setToggle to update the toggle variable. The initial value of toggle is set to false.

  return (
  <nav 
  className={`${styles.paddingX} w-full flex items-center py-5 fixed top-0 z-20 bg-primary`}>
  <div className='w-full flex justify-between items-center max-w-7x1 mx-auto'>
    <Link to="/" className='flex items-center gap-2' onClick={()=>{setActive("");
    window.scrollTo(0,0);
  }}>
    <img src={logo} alt="logo" className='w-9 h-9 object-contain'/>
   <p className='text-white text-[18px]font-bold cursor-pointer flex'>Anshita</p>
    </Link>
    <ul className='list-none hidden sm:flex flex-row gap-10'>
      {navLinks.map((nav)=>(
        <li
        key={nav.id}
        className={`${active===nav.title ? "text-white" : "text-secondary"} hover:text-white text-[18px] font-medium cursor-pointer`}
        onClick={()=> setActive(nav.title)}
        >
         
          <a href={`#${nav.id}`}>{nav.title}</a>
        </li>
      ))}

    </ul>
    {/* below div for mobile devices that is how nav bar will look in smaller devices */}
    <div className='sm:hidden flex flex-1 justify-end items-center' >
      <img
      src={toggle ? close: menu} //show menu icon if nav bar is currently closed and when menu icon is clicked , show close or cross button
      alt='menu'
      className='w-[28px] h-[28px] object-contain cursor-pointer'
      onClick={()=>setToggle(!toggle)}
      />
      {/* now we have created menu and close buttons and now we want to show the nav bar options when toggled ,so below div is for that */}
      <div
            className={`${
              !toggle ? "hidden" : "flex"
            } p-6 black-gradient absolute top-20 right-0 mx-4 my-2 min-w-[140px] z-10 rounded-xl`}
          >
<ul className='list-none flex  flex justify-end items-start flex-col gap-4'>
      {navLinks.map((nav)=>(
        <li
        key={nav.id}
        className={`${active===nav.title ? "text-white" : "text-secondary"} hover:text-white font-poppins text-[16px] font-medium cursor-pointer`}
        onClick={()=>{ 
          setToggle(!toggle); 
          setActive(nav.title)}}
        > 
        {/* when we will click on about,work..then also menu will close  */}
         
          <a href={`#${nav.id}`}>{nav.title}</a>
        </li>
      ))}

    </ul>
      </div>
    </div>
  </div>
  </nav>
  )
}

export default Navbar