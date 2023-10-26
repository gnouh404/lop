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
function checkEmail(txt){
    var filter = /^([a-zA-Z0-9_\.\-])+\@(([a-zA-Z0-9\-])+\.)+([a-zA-Z0-9]{2,4})+$/;
    if(!filter.test(txt.value)){
        return false;
    }
    return true;
}

function validform(f)
{
	
	if(checknull(f.email))
	{
		alert(f.email.name + " must be not null");
		f.email.focus();
		return;
	}
    if(!checkEmail(f.email)){
        alert("Phai nhap Email hop le theo dang: email@gmail.com");
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
    alert("Form submitted succesfully")
}


