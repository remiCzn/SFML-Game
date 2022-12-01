import {Server} from "socket.io";

const io = new Server(3000);

io.on("connection", (socket) => {
    console.log("Connected: ", socket.id);
    socket.emit("hello", "world");

    socket.on("howisit", (arg) => {
        console.log(arg);
    })

    socket.on("disconnect", (reason) => {
        console.log(reason);
    })
})