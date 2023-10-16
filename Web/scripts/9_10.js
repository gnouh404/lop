function checknull(txt)
{
	if(txt.value.length==0)
		return true;
	else
		return false;
}

function validform(f)
{
	
	if(checknull(f.fullname))
	{
		alert(f.fullname.name + " must be not null");
		f.fullname.focus();
		return;
	}
	if(checknull(f.age))
	{
		alert(f.age.name + " must be not null");
		f.age.focus();
		return;
	}
	if(isNaN(f.age.value))
	{
		alert(f.age.name + " must be a number");
		f.age.value="";
		f.age.focus();
		return;
	}
	if(!isInteger(f.age))
	{
		alert(f.age.name + " must be an integer number");
		f.age.value="";
		f.age.focus();
		return;
	}
	if(eval(f.age.value)<=0 )
	{
		alert(f.age.name + " must be greater than 0");
		f.age.value="";
		f.age.focus();
		return;
	}
	if(notCheck() ==  false)
	{
		alert("gender must be choosen")
		return;
	}   
	if(isNaN(f.phone.value))
	{
		alert(f.phone.value + " not valid");
		return;
	}

    alert("Form submitted succesfully");
}
function StringMatch(txt, reg)
{
	return reg.test(txt.value);	
}
function notCheck()
{
    var radio = document.forms.frmAccount
	var rt=false;
	for(i=0; i<radio.length; i++){
        if(radio[i].checked){
            rt=true;
        }	
    }
	return rt;
}
function isInteger(txt)
{
	
	if((!isNaN(txt.value)) && (parseInt(txt.value)===Number(txt.value)))
		return true;
	else
		return false;
}