function calculate(){
    var op1 = document.getElementById("op1").value;
    var op2 = document.getElementById("op2").value;

    if(document.getElementById("add").checked){
        var x = parseInt(op1)
        var y = parseInt(op2)
        document.getElementById("answer").innerHTML = x+y;
    }else if(document.getElementById("sub").checked){
        var x = parseInt(op1)
        var y = parseInt(op2)
        document.getElementById("answer").innerHTML = (x-y);
    }else if(document.getElementById("mul").checked){
        var x = parseInt(op1)
        var y = parseInt(op2)
        document.getElementById("answer").innerHTML = (x*y);
    }else if(document.getElementById("div").checked){
        var x = parseInt(op1)
        var y = parseInt(op2)
        if(y == 0){
            document.getElementById("answer").innerHTML = "division by zero error"
        }else{
        document.getElementById("answer").innerHTML = (x/y);
        }
    }
}
