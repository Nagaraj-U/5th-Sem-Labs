function result(){
    var dollars = parseInt(prompt("enter dollar value"))
        var rupees = dollars * 64;
        document.writeln("result of dolar -> rupees is " + rupees)
        document.writeln();

        var rupees1 = parseInt(prompt("enter rupees"));
        var dollars1 = (rupees1/64);
        document.writeln("rupees -> dollars" + dollars1);

        var euros = parseInt(prompt("enter euros"));
        var rupees3 = (euros*89);
        document.writeln("euros -> rupees" + rupees3);
        document.writeln();

        var rupees4 = parseInt(prompt("enter rupees"));
        var euros1 = (rupees4 / 89);
        document.writeln("rupees -> euros" + euros1)
}