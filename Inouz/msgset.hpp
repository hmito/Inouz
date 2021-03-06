﻿#ifndef INOUZ_MSGSET_INC
#define INOUZ_MSGSET_INC 100
#
#include "iomessage.hpp"
namespace inouz{
	namespace msgset{
		struct client_interface{
		public:
		private:
			id_type ID;
			omessage* pOut;
		public:
			client_interface(id_type ID_):ID(ID_){}
			void open();
		public:
			//ロック要求
			void send_lock(id_type TergetID);
			//ロック要求に返答 ack:ack/nack relock:逆ロック要求
			void send_reply_lock(id_type TergetID, bool ack, bool relock=false);
			//アンロック要求
			void send_unlock(id_type TergetID);
			//アンロック要求を受諾
			void send_reply_unlock(id_type TergetID, bool ack);
			//通信要求
			void send_ping(id_type TergetID);
			//通信要求返答
			void send_pong(id_type TergetID);
			//パス要求
			void send_request();
			//パスデータ通知
			void send_path(point_type begin,point_type end, path_result::type rst);
		public:
			//ロック要求
			virtual void recv_lock(id_type TergetID);
			//ロック要求を受諾
			virtual void recv_reply_lock(id_type TergetID, bool ack, bool relock = false);
			//アンロック要求
			virtual void recv_unlock(id_type TergetID);
			//アンロック要求を受諾
			virtual void recv_reply_unlock(id_type TergetID, bool ack);
			//通信要求
			virtual void recv_ping(id_type TergetID);
			//通信要求返答
			virtual void recv_pong(id_type TergetID);
			//パス要求
			virtual void recv_request();
			//パスデータ通知
			virtual void recv_path(point_type begin, point_type end, path_result::type rst);
		};
	}
}
#
#endif
