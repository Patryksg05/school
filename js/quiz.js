document.querySelectorAll("button")[0].addEventListener("click", function(){
    let check = document.getElementsByName("check");
    let color = "#";
    for(let i=0; i<check.length; i++)
        if(check[i].checked)
            color += "FF";
        else 
            color += "00";
    document.querySelectorAll("button")[0].style.backgroundColor = color;
});

function changeColor(x)
{
    document.getElementById("text").style.color = x.value;
}