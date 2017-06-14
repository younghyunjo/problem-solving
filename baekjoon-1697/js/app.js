function parseInput(inputBuffer) {
  var input = inputBuffer.toString('utf8', 0, inputBuffer.length-1).split(' ');

  return {
    from: Number(input[0]),
    to: Number(input[1])
  };
}

function bfs(from, to) {
  var hits = [];

  if (from === to)
    return 0;

  var cnt = 1;
  var i;
  var movablePoint = [from-1, from+1, from*2];;

  do {
    var nextPoints = movablePoint.slice();
    if (nextPoints.indexOf(to) !== -1)
      break;
    movablePoint = [];

    cnt++;

    for (i=0; i<nextPoints.length; i++) {
      hits[nextPoints[i]] = 1;
    }


    for (i=0; i<nextPoints.length; i++) {
      p = nextPoints[i];
      if (p > 1000000) {
        continue;
      }
      if (movablePoint.indexOf(p-1) === -1 && hits[p-1] === undefined) {
        movablePoint.push(p-1);
      }
      if (movablePoint.indexOf(p+1) === -1 && hits[p+1] === undefined && p+1 <= 100000) {
        movablePoint.push(p+1);
      }
      if (movablePoint.indexOf(p*2) === -1 && hits[p*2] === undefined && p*2 <= 100000) {
        movablePoint.push(p*2);
      }
    }
  }
  while (1);


  return cnt;
}


process.stdin.resume();
process.stdin.on('data', function (inputBuffer) {
  var input = parseInput(inputBuffer);
  var cnt = bfs(input.from, input.to);

  console.log(cnt);
});


