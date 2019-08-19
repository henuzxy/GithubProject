1. 为什么连接是三次握手，而断开确实四次挥手?

   因为建立连接的时候，双方没有数据的来往，可以把ACK和SYN放到一个报文进行发送。

   但在关闭连接时，收到FIN报文后，它表示对方没有数据需要再发送了，但自己可能还有数据要发给对方，这是发送一个ACK报文，表示自己收到了FIN报文。当自己也没有数据需要发送的时候，就发送一个FIN表示你现在同意关闭连接了，对面再发送一个ACK即完成断开。

2. 为什么CLIENT主机最后一次发送ACK后不立即断开，而是经过TIME_WAIT状态经过2MSL(最大报文生存时间)后才返回到CLOSE状态？

   因为网络时不可靠的，有可能最后一个ACK会丢失，SERVER端如果没有收到ACK，会再次发送FIN报文，所以CLIENT主机不能立即关闭，他需要确认SERVER端收到了ACK。CLIENT进入TIME_OUT状态后，会设置一个计时器，等待2MSL后进入CLOSE状态，如果在这个时间内再次收到FIN，就会重新发送ACK，并重新等待2MSL.

3. 为什么不能用两次握手进行连接？

   - 防止已经失效的连接请求报文又传到服务器，因而产生错误。当client发送一个请求连接后，在某个网络节点发生延迟，某个时间才到达server端，本来这是一个失效的报文。但B受到后，会发送一个SYN+ACK，如果这时采用的是两次握手，那么表示已经建立连接，但A端这时可能并没有要求建立连接，这样就会造成资源浪费。
   - 在不可靠的信道上可靠的传输信息。如果是两次握手就完成连接的话，当server端发送SYN+ACK之后。如果这条消息并未发送成功，那么CLIENT会继续发送SYN，这样server端会建立多个无效连接。
   - 确保双方对序列号达成一致，当server发送SYN+ACK+seq，表示自己从这个序列号开始发送，但无法确保这个消息被成功发送，必须收到ACK后，才能确定双方对序列号达成一致。best

4. 如果已经建立连接，但客户端出现故障会怎么办？

5. 如何优雅的断开套接字连接？

   close函数意味着完全断开连接。A主机发送完数据后，调用close关闭连接，之后再也无法接收主机B传输的数据。这时就可以使用半关闭，考虑这种情况，服务端将约定的文件发送给客户端后，客户端收到后发送“Thank you”字符串给服务端。
   
6. 什么时候会出现大量的TIME-WAIT状态？

   当请求量很大，并且大多是短连接请求的时候，就会在服务器出现大量的TIME-WAIT状态。
   
7. http的缺点有哪些？
	- 使用明文（不加密），内容可能会被窃听
	- 不验证通信方的身份，因此有可能遭遇伪装
	- 无法验证报文的完整性，可能被修改
	
8. 如何防止报文被窃听？

   1. 对通信加密，即通过SSL建立安全的通信线路，之后在这个线路上进行http通信。
   2. 对内容加密，即把http报文所包含的内容进行加密，但要求客户端和服务端都要具有**加密和解密**机制。当该方式内容有可能被修改。因为通信通道无法保证是安全的。

9. 不验证通信的身份会有哪些隐患?

   1. 无法确定自己发送的目标服务器是否是伪装服务器。同理，无法判断是否伪装客户端。
   2. 无法确定对方对于某些资源是否具有访问权限。
   3. 无意义的请求也会被接收，无法阻止DOS攻击