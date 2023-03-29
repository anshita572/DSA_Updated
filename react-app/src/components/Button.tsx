interface Props{
    children:string
}
interface Props{
    children:string;
    onClick:()=>void;
}
export const Button = ({children,onClick}:Props) => {
  return (
    <button className="btn btn-primary" onClick={onClick
    }>{children}</button>
  )
}
