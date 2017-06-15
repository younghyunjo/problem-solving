function parseInput(inputBuffer) {
  var inputArray = inputBuffer.toString().split('\n');
  var row = inputArray[0].split(' ')[0];
  var column = inputArray[0].split(' ')[1];

  var graph = [];
  for (var i=0; i<column; i++) {
    graph[i] = inputArray[i+1].split(' ').map(Number);
  }

  return {
    row: row,
    column: column,
    graph: graph
  }
}

function getRipenDays(depot) {
  var BOUNDARY = 999;

  function searchObjectInArray(array, object) {
    var found = array.filter(function (m) {
      if (JSON.stringify(m) === JSON.stringify(object)) {
        return true;
      }
      return false;
    });

    return found;
  }

  function hitsCacheInit(row, column, depot) {
    var hitsCache = [];

    for (var y=0; y<column; y++) {
      hitsCache[y] = [];
      for (var x=0; x<row; x++) {
        if (depot[y][x] === -1) {
          hitsCache[y][x] = 1;
        }
        else {
          hitsCache[y][x] = undefined;
        }
      }
    }
    return hitsCache;
  }

  function searchTomato(depot) {
    var column = depot.length;
    var row = depot[0].length;
    var tomatos = [];

    for (var y=0; y<column; y++) {
      for  (var x=0; x<row; x++) {
        if (depot[y][x])
          tomatos.push({'y': y, 'x': x, 'depth': 0});
      }
    }
    return tomatos;
  }

  var row = depot[0].length;
  var column = depot.length;
  var hits = hitsCacheInit(row, column, depot);

  var tomatos = searchTomato(depot);
  if (tomatos === undefined)
    return undefined;

  var stepX = [0, 0, 1, -1];
  var stepY = [-1, 1, 0, 0];

  var queue = [];
  tomatos.forEach(function (tomato) {
    queue.push(tomato);
  });

  do {
    var point = queue.shift();
    if (hits[point.y][point.x] !== undefined)
      continue;

    hits[point.y][point.x] = 1;

    for (var i=0; i<4; i++) {
      var x = point.x + stepX[i];
      var y = point.y + stepY[i];
      //console.log('y:'+y+' x:'+x);

      if (x > BOUNDARY || y > BOUNDARY || x >= row || y >= column || x < 0 || y < 0)
        continue;

      if (hits[y][x] === undefined) {
        queue.push({'y': y, 'x': x, 'depth': point.depth+1});
      }
    }
  } while(queue.length);

  return point.depth;
}

process.stdin.resume();
process.stdin.on('data', function (inputBuffer) {
	var input = parseInput(inputBuffer);

  var ripenDays = getRipenDays(input.graph); 
  console.log(ripenDays);
})
