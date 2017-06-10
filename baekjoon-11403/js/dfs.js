function parseInput(inputBuffer) {
	var inputArray = inputBuffer.toString().split('\n');
	var nrRow = inputArray[0];
	var graph = [];

	for (var i=0; i<nrRow; i++) {
		graph[i] = inputArray[i+1].split(' ');
	}

	return {
		nrRow: nrRow,
		graph: graph
	};
}

function hasPath(from, to, graph) {
	var found = 0;
	var hit = [];
	var stack = [];

	stack.push(from);

	do {
		from = stack.pop();
		graph[from].map(function (value, index) {
			if (value == 0) {
				return;
			}

			if (index == to) {
				found = 1;
				return;
			}

			if (hit.indexOf(index) === -1) {
				hit.push(index);
				stack.push(index);
				return;
			}
		});

		if (found) {
			return 1;
		}
	} while (stack.length > 0)

	return 0;
}


process.stdin.resume();
process.stdin.on('data', function (inputBuffer) {
	var input = parseInput(inputBuffer);

	for (var i=0; i<input.nrRow; i++) {
		var result = [];
		for (var j=0; j<input.nrRow; j++) {
			result.push(hasPath(i, j, input.graph));
		}
		console.log(result.join(' '));
	}
});
