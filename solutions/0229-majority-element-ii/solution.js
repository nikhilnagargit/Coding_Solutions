/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    const l = nums.length;
    let hashTable = new Map();
    nums.forEach((num)=>{
        if(hashTable.has(num)){
            hashTable.set(num,hashTable.get(num)+1);
        }
        else{
            hashTable.set(num,0);
        }
    })
    
    const max_pair = [...hashTable.entries()].reduce((accumulator, element) => {
     return element[1] > accumulator[1] ? element : accumulator;
     });

     hashTable.delete(max_pair[0]);


     if(hashTable.size!==0){

 var second_max_pair = [...hashTable.entries()].reduce((accumulator, element) => {
     return element[1] > accumulator[1] ? element : accumulator;
     });
     }
     else{
        return [max_pair[0]];
     }

     const  arr = []
     if(max_pair[1]>=Math.floor(l/3)){
            arr.push(max_pair[0]);
     }
     if(second_max_pair[1]>=Math.floor(l/3)){
            arr.push(second_max_pair[0]);
     }
     return arr;

};
