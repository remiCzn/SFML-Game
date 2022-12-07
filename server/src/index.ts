import {Server} from "socket.io";

const io = new Server(3000);

interface IHash<T> {
    [i: string]: T
}

interface Player {
    position: {
        x: number,
        y: number
    }
}

let players: IHash<Player> = {};

io.on("connection", (socket) => {
    players[socket.id] = {
        position: {
            x: 0,
            y: 0
        }
    }

    socket.on("position", (arg) => {
        players[socket.id].position = JSON.parse(arg)
        console.log(players);
    })

    socket.on("disconnect", (reason) => {
        delete players[socket.id];
        console.log(reason);
    })
});