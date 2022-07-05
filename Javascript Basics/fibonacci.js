//Fibonacci sequence

function fibonaaci(x)
  {
    var ans=[];
    
    if(x===1)
    {ans.push(0);}
    else if (x==2)
    {ans.push(0,1);}
    else //if(x > 2)
    {ans=[0,1];
      for(var i=2;i<x;i++)
      { var n=ans.length;
      var next = ans[n-2] + ans[n-1];
      ans.push(next);
      }
    }
    return ans;
  }
fibonaaci(8);