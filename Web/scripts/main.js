

function show(){
    var div = document.getElementById("product");
    if(div.style.display != "grid"){
        document.getElementById("view").style.display = "none";
        div.style.display = "grid";
        document.getElementById("view_next").style.display = "block";
    }  
}
function show_next(){
    var div = document.getElementById("product_next");
    if(div.style.display != "grid"){
        document.getElementById("view_next").style.display = "none";
        div.style.display = "grid";
       
    }  
}

function show_menu2(){
    var div = document.getElementById("product2");
    if(div.style.display != "grid"){
        document.getElementById("view2").style.display = "none";
        div.style.display = "grid";
        document.getElementById("view_next2").style.display = "block";
    } 
}

function show_next2(){
    var div = document.getElementById("product_next2");
    if(div.style.display != "grid"){
        document.getElementById("view_next2").style.display = "none";
        div.style.display = "grid";
       
    }  
}

function show_menu3(){
    var div = document.getElementById("product3");
    if(div.style.display != "grid"){
        document.getElementById("view3").style.display = "none";
        div.style.display = "grid";
        document.getElementById("view_next3").style.display = "block";
    } 
}

function show_next3(){
    var div = document.getElementById("product_next3");
    if(div.style.display != "grid"){
        document.getElementById("view_next3").style.display = "none";
        div.style.display = "grid";
       
    }  
}
var isclick = true;
function showandhide_category(){
    var topleft = document.querySelector(".left-top");
    if (isclick) {
        topleft.style.display = "block";
        isclick = false;
    }
    else {
        topleft.style.display = "none";
        isclick = true;
    }
}
function showandhide_categorydown(){
    var downleft = document.querySelector(".left-down");
    if (isclick) {
        downleft.style.display = "block";
        isclick = false;
    }
    else {
        downleft.style.display = "none";
        isclick = true;
    }
}



