/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {

    let stack = new Array();
    let open_list = new Set(["(","[","{"]);
    let close_list = new Set([")","]","}"]);

    for(let i=0;i<s.length;i++){
        let c = s[i];
        if(open_list.has(c)){
            stack.push(c);
        }
        else if(c===")"){
            if(stack.pop()!=="("){
                return false;
            }
        }
        else if(c==="]"){
            if(stack.pop()!=="["){
                return false;
            }
        }
        else if(c==="}"){
            if(stack.pop()!=="{"){
                return false;
            }
        }
        else{
            return false;
        }
    }
    if(stack.length===0)
    return true;
    return false;
};
