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
