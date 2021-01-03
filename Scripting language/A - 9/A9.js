function result(){
    var str = document.getElementById("str").value;
    var p = [];
    p = str.split(" ");
    var singleWord;
    var len = 0;
    for(var i=0;i<p.length;i++){
        if(len < p[i].length){
            len = p[i].length;
            singleWord = p[i];
        }
    }

    document.getElementById("word").innerHTML = singleWord;
    document.getElementById("strlen").innerHTML = len;
}