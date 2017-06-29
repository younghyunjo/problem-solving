function parseInput(inputBuffer) {
	var inputArray = inputBuffer.toString().split('\n');
	var nrRow = inputArray[0];
  var ropes = [];

	for (var i=0; i<nrRow; i++) {
    ropes[i] = Number(inputArray[i+1]);
	}

  ropes = ropes.sort(function (a, b) {
    return b-a;
  });

	return {
		nrRow: nrRow,
		ropes: ropes
	};
}

function findMaxWeight(ropes) {
  var weight = 0;
  var maxWeight = 0;
  var nrUsingRopes = 0;

  for (var i=0; i<ropes.length; i++) {
    weight = ropes[i] * (nrUsingRopes+1); 
    if (weight >= maxWeight) {
      maxWeight = weight;
      nrUsingRopes++;
    }
  }
  return maxWeight;
}

process.stdin.resume();
process.stdin.on('data', function (inputBuffer) {
  var input = parseInput(inputBuffer);
  var maxWeight = findMaxWeight(input.ropes);
  console.log(maxWeight);
});
