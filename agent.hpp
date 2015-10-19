#ifndef INOUZ_AGENT_INC
#define INOUZ_AGENT_INC 100
#
#include "msgset.hpp"
#include "map.hpp"
#include "movement_interface.hpp"
#include "navigate.hpp"
namespace inouz{
	struct agent{
		typedef agent my_type;
	private:
		//ロックされた数
		unsigned int LockCnt;
		//動けるかどうか
		bool Moveable;
		//地図保存モジュール
		map Map;
		//ナビゲータモジュール
		navigate Navi;
		//動力モジュール
		movement_interface* pMove;
	private:
		//送受信用モジュール
		struct client :public msgset::client_interface{
		private:
			my_type& ref;
		public:
			client(id_type ID_, my_type& ref_):ref(ref_), msgset::client_interface(ID_){}
		public:
			//ロック要求
			void recv_lock(id_type TergetID)override{
				if(ref.LockCnt > 0){
					++(ref.LockCnt);
					send_ack_lock(TergetID);
				}
			}
			//ロック要求を受諾
			void recv_ack_lock(id_type TergetID)override;
			//ロック要求を拒否
			void recv_nak_lock(id_type TergetID)override;
			//ロック要求を拒否し、逆ロック要求
			void recv_rev_lock(id_type TergetID)override;
			//アンロック要求
			void recv_unlock(id_type TergetID)override;
			//アンロック要求を受諾
			void recv_ack_unlock(id_type TergetID)override;
			//通信要求
			void recv_ping(id_type TergetID)override;
			//通信要求返答
			void recv_pong(id_type TergetID)override;
			//パス要求
			void recv_request()override;
			//パスデータ通知
			void recv_path(point_type begin, point_type end, path_result::type rst)override;
		}Client;
		typedef msgset::client_interface::id_type id_type;
	public:
		agent(id_type ID_)
			: LockCnt(0)
			, Moveable(false)
			, Map()
			, Navi()
			, Client(ID_,*this){
		}
		void operator()(void){
			//Free Statusのとき
			if(LockCnt == 0 && !Moveable){
				Client.send_lock(3);
			}
		}
	};
}
#
#endif
