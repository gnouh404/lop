function checknull(txt)
{
	if(txt.value.length==0)
		return true;
	else
		return false;
}

function StringMatch(txt, reg)
{
	return reg.test(txt.value);	
}
function isInteger(txt)
{
	
	if((!isNaN(txt.value)) && (parseInt(txt.value)===Number(txt.value)))
		return true;
	else
		return false;
}

function validform(f)
{
	
	if(checknull(f.email))
	{
		alert(f.email.name + " must be not null");
		f.email.focus();
		return;
	}
	if(checknull(f.rate))
	{
		alert(f.rate.name + " must be not null");
		f.rate.focus();
		return;
	}
    
	if(isNaN(f.rate.value))
	{
		alert(f.rate.name + " must be a number");
		f.rate.value="";
		f.rate.focus();
		return;
	}
	if(!isInteger(f.rate))
	{
		alert(f.rate.name + " must be an integer number");
		f.rate.value="";
		f.rate.focus();
		return;
	}
	if(eval(f.rate.value)<=0 || eval(f.rate.value)>=10)
	{
		alert(f.rate.name + " must be in (0-10)");
		f.rate.value="";
		f.rate.focus();
		return;
	}
    alert("Form submitted succesfully");
}
