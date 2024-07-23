// https://leetcode.com/problems/flatten-deeply-nested-array/

/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */

const flattenOneLevel = (array) => {
    const result = [];
    array.forEach(item => {
        if (Array.isArray(item)) {
            result.push(...item);
        } else {
            result.push(item);
        }
    });
    return result;
};

var flat = function (arr, depth) {
    if (depth === 0) return arr;

    let result = arr;
    while (depth > 0) {
        result = flattenOneLevel(result);
        depth--;
    }

    return result;
};