
    
function displayColor(tcolor){
    var currentcolor = document.getElementById("colordisplay")
    if (tcolor === 'green'){
        currentcolor.setAttribute('style', 'background-color:#7cc576;border:1px solid #197b30');
        currentcolor.innerHTML = 'The current color is green';
    } else if (tcolor === 'red'){
        currentcolor.setAttribute('style', 'background-color:#9e0b0f;border:1px solid #790000')
        currentcolor.innerHTML = 'The current color is red';
    } else if (tcolor==='blue'){
        currentcolor.setAttribute('style', 'background-color:#00bff3;border:1px solid #0076a3')
        currentcolor.innerHTML = 'The current color is blue';        
    } else {
        currentcolor.innerHTML = 'E: '.concat(tcolor);
    }
}

function changeColor(color){
    $.ajax({ url: "change.php?c=".concat(color), success: function(data){
        console.log('Color is now '.concat(data));
        displayColor(data)
    }, dataType: "html", timeout: 30000});
}

(function initColor(){
    $.ajax({ url: "file.txt", success: function(data){
        displayColor(data);
        console.log("The starting color is ".concat(data));
    }, dataType: "html", timeout: 30000}); 
})();