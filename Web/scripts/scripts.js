alert("Welcome to my chanel!");
document.write("Hello world!");
var n = 20;
var i = 0;
document.write("<br>Display the odd number <br>");
while (i <= n) {
    if (i % 2 == 0)
        document.write(i + "\t");
    i++;
}
function doclick(tag) {
    tag.style = "background: linear-gradient(90deg, blue, red";
    tag.innerHTML = "Hello";
}
var p = document.querySelector('p.text-white');
var footer = document.getElementById('footer');
p.onclick = function doclick() {
    alert('onclick');
    p.innerHTML = "Hello world!";
    p.style = "background: linear-gradient(90deg, blue, red";
} 

function myFunction() {
    document.getElementById("pf").innerHTML = "hello";
}






