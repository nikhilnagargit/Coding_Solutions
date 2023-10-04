/**
 * @param {number} money
 * @param {number} children
 * @return {number}
 */
var distMoney = function(money, children) {

if(money<children){
    return -1;
}

if(money===children){
    return 0;
}

let arr = new Array(children).fill(1);
let remaining_money =money-children;

// give one by one
let i=0;
while(remaining_money>0){
    arr[i] ++;
    remaining_money--;

    if(arr[i]===8){
        i++;
    }

    if(i===children){
        i=0;
    }

}



// check for 4s and 8s in array
let fours = 0;
let eights = 0;

arr.forEach((i)=>{
    if(i===4){
        fours++;
    }
    if(i===8){
        eights++;
    }
})

// when no 4s
if(fours===0){
    return eights;
}

// check [8,8,4] situation
if(fours===children-eights){
    return eights-1;
}
 
//  check [8,4....,1] situation
return eights;

};
