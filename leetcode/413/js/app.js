/**
 * @param {number[]} A
 * @return {number}
 */
var numberOfArithmeticSlices = function (A) {
  var sum = 0;
  var len = 2;

  for (var i=2; i<A.length; i++) {
    if ((A[i] - A[i-1]) === (A[i-1] - A[i-2])) {
      len += 1;
    }
    else {
      sum += calcSum(len);
      len = 2;
    }
  }

  if (len > 2)
    sum += calcSum(len);

  return sum;
};

function calcSum(n) {
  return (n-1)*(n-2)/2;
}

