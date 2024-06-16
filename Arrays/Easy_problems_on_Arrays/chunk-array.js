// https://leetcode.com/problems/chunk-array/

/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let len = arr.length;
    if (len == 0) {
        return [];
    }
    let ans = [];

    for (let i = 0; i < len; i += size) {
        let tempArr = [];
        for (let j = i; j < i + size; j++) {
            if (arr[j] != null) {
                tempArr.push(arr[j]);
            }
        }
        ans.push(tempArr)
    }

    return ans;
};