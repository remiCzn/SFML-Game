"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const socket_io_client_1 = require("socket.io-client");
const socket = (0, socket_io_client_1.io)("ws://localhost:3000");
socket.on("hello", (arg) => {
    console.log(arg);
});
socket.emit("howareyou", "I'm good", "and it's ok");
socket.disconnect();
