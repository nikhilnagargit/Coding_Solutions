/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    
    if(s===""){
      return 0;
    }

    let s_start= 0;
    let s_end= 0;
    let i=1;
    let max_len = 1;
    let curr =  "";
    while(i<s.length){
      curr = s[i];
      //check if current char is in our sliding window
      let flag = -1;
      for(let j=s_start;j<=s_end;j++){
        if(curr===s[j]){
          flag = j;
        }
      }
      // if found in sliding window
      if(flag!=-1){
        s_start = flag+1;
        s_end +=1;
      }
      else{
        s_end+=1;
      }
      i++;
      max_len = Math.max(max_len,s_end-s_start+1);
    }
    return max_len;
};
