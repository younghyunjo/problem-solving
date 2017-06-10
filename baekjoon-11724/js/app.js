function parseInput(inputBuffer) {
	var inputArray = inputBuffer.toString().split('\n');
	var nrVertex = inputArray.shift().split(' ')[0];

	var graph = [];
	for (var i=0; i<=nrVertex; i++) {
		graph[i] = [];
	}

	inputArray.map(function (value) {
		if (value.length != 3)
			return;

		var edgeInfo = value.split(' ');

		if (edgeInfo.length != 2)
			return;

		var a = Number(edgeInfo[0]);
		var b = Number(edgeInfo[1]);

		if (!a)
			return;
		if (!b)
			return;
		if (a >= graph.length || b >= graph.length)
			return;

		graph[a].push(b);
		graph[b].push(a);
	});

	return {
		nrVertex: nrVertex,
		graph: graph,
	};
}

function dfs(from, graph, hit) {
	var stack = [];

	stack.push(from);

	do {
		from = stack.pop();

		if (hit.indexOf(from) === -1) {
			hit.push(from);

			graph[from].filter(function(v) {
				return (stack.indexOf(v) < 0) && (hit.indexOf(v) < 0);
			}).map(function(v) {
				stack.push(v);
			});
		}
	}
	while (stack.length > 0);
}

function countComponent(nrVertex, graph) {
	var hit = [];
	var vertex = [];
	for (var i=1; i<=nrVertex; i++) {
		vertex.push(i);
	}

	var nrComponent = 1;
	var start = Number(1);

	while (1) {
		dfs(start, graph, hit);

		if (hit.length >= nrVertex)
			break;

		nrComponent++;
		start = vertex.filter(function (v){return hit.indexOf(v) < 0})[0];
	}

	return nrComponent;
};

process.stdin.resume();
process.stdin.on('data', function (inputBuffer) {
	var input = parseInput(inputBuffer);
	var nrComponent = countComponent(input.nrVertex, input.graph);
	console.log(nrComponent);
});
