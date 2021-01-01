function test(){
    var num = document.getElementById("num").value;
    if(num%3 == 0 || num%7 == 0){
        document.getElementById("answer").innerHTML = "number is divisible by 3 or 7";
    }else{
        document.getElementById("answer").innerHTML = "number is not divisible";
    }
}