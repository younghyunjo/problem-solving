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

function findStart(row, column, hits) {
  for (var y=0; y<column; y++) {
    for (var x=0; x<row; x++) {
      if (hits[y][x] === undefined) {
        return [y, x];
      }
    }
  }
  return undefined;
}

function isItemInArray(array, item) {
  for (var i = 0; i < array.length; i++) {
    // This if statement depends on the format of your array
    if (array[i][0] == item[0] && array[i][1] == item[1]) {
      return true;   // Found it
    }
  }
  return false;   // Not found
}

function dfs(startPoint, walls, hits, roomNumber, neighbor) {
  var BOUNDARY = 49;

  function exploring(x, y, dirInfo) {
    var nextX = x;
    var nextY = y;
    if (dirInfo['x']) {
      nextX = x + dirInfo['x'];
    }
    else if (dirInfo['y']) {
      nextY = y + dirInfo['y'];
    }
    else {
      return undefined;
    }

    if (nextY < 0 || nextX < 0 ||
      x >= row || y >= column ||
      nextX >= row || nextY >= column ||
      nextX > BOUNDARY || nextY > BOUNDARY) {
      return undefined;
    }

    var nextPointString = nextY.toString() + ',' + nextX.toString();

    if (((walls[y][x] & dirInfo['flag']) === 0) && (hits[nextY][nextX] === undefined)) {
      if (isItemInArray(stack, [nextY, nextX]) === true) {
      }
      else {
        stack.push([nextY, nextX]);
      }

      var index = neighbor.indexOf(y.toString() + ',' + x.toString());
      if (index >= 0) {
        neighbor.slice(index, 1);
      }
    }
    else {
      if (neighbor.indexOf(nextPointString) === -1) {
        if (hits[nextY][nextX] !== roomNumber) {
          neighbor.push(nextPointString);
        }
      }
    }
  }

  var row = walls[0].length;
  var column = walls.length;
  var roomSize = 0;
  var stack = [startPoint];
  var directions = {
    'e': { 'x': 1, 'flag': 0x4 },
    'w': { 'x': -1, 'flag': 0x1 },
    'n': { 'y': -1, 'flag': 0x2 },
    's': { 'y': 1, 'flag': 0x8 },
  };

  do {
    var coord = stack.pop();
    var y = coord[0];
    var x = coord[1];

    hits[y][x] = roomNumber;
    Object.keys(directions).forEach(function (dir) {
      exploring(x, y, directions[dir]);
    });

    roomSize++;
  } while(stack.length);


  return roomSize;
}


function countRoom(walls, hits) {
  var column = walls.length;
  var row = walls[0].length;

  var startPoint = findStart(row, column, hits);
  var roomNumber = 0;
  var roomsSize = []
  var neighbor = [];

  while (startPoint !== undefined) {
    neighbor[roomNumber] = [];
    var roomSize = dfs(startPoint, walls, hits, roomNumber, neighbor[roomNumber]);
    roomsSize[roomNumber++] = roomSize;

    startPoint = findStart(row, column, hits);
  }

  console.log(roomsSize.length);
  console.log(Math.max.apply(null, roomsSize));

  var maxTwoRoomSize = 0;
  roomsSize.forEach(function (size, index) { 
    var neighborPoint;
    var myRoom = index;
    while (1) {
      neighborPoint = neighbor[index].pop();
      if (neighborPoint === undefined) 
        break;

      var y = parseInt(neighborPoint.split(',')[0]);
      var x = parseInt(neighborPoint.split(',')[1]);
      
      var neighborRoom = hits[y][x];
      if (myRoom !== neighborRoom) {
        var twoRoomSize = roomsSize[myRoom] + roomsSize[neighborRoom];
        maxTwoRoomSize = twoRoomSize > maxTwoRoomSize ? twoRoomSize : maxTwoRoomSize;
      }
    }
    

  });
  console.log(maxTwoRoomSize);
}

process.stdin.resume();
process.stdin.on('data', function (inputBuffer) {
	var input = parseInput(inputBuffer);

  var roomTag = [];
  for (var y=0; y<input.column; y++) {
    roomTag[y] = [];
    for (var x=0; x<input.row; x++) {
      roomTag[y][x] = undefined;
    }
  }

  countRoom(input.graph, roomTag);
});
