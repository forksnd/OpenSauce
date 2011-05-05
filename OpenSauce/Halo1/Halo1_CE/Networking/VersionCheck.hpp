/*
    Yelo: Open Sauce SDK
		Halo 1 (CE) Edition
    Copyright (C) 2005-2010  Kornner Studios (http://kornner.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#ifdef YELO_VERSION_CHECK_ENABLE

namespace Yelo
{
	namespace Networking { namespace VersionCheck
	{
		void		Initialize();
		void		Dispose();

#ifdef PLATFORM_IS_USER
		void		Initialize3D(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pParameters);
		void		OnLostDevice();
		void		OnResetDevice(D3DPRESENT_PARAMETERS* pParameters);
		void		Render();
		void		Release();
#endif

		void		LoadSettings(TiXmlElement* dx9_element);
		void		SaveSettings(TiXmlElement* dx9_element);

		void		InitializeForNewMap();
		void		Update(real delta_time);

		/*!
		 * \brief
		 * Checks for a newer OS version and informs the user.
		 * 
		 * The version check manager will download an XML file from
		 * a predetermined location, which contains the currently
		 * available version of OpenSauce. It will then display this
		 * to the user if a newer version is available.
		 */
		class c_version_check_manager_base
			abstract
		{
		private:
			/// A hardcoded fallback xml location used when no other location is provided.
			static cstring g_fallback_xml_location;

		private:
			/** Callback function for the ghttp get calls. */
			static GHTTPBool GetRequestComplete(GHTTPRequest request,
				GHTTPResult result,
				char* buffer,
				GHTTPByteCount bufferLen,
				char* headers,
				void* param);
		public:
			/** Returns a reference to a static instance of c_version_check_manager_base. */
			static c_version_check_manager_base& VersionChecker();

		protected:
			struct {
				/// Has the version xml been downloaded today
				bool checked_today;
				/// Is there a new version available
				bool is_new_version;
				/// Is there a request in progress
				bool is_request_in_progress;
				PAD8;

				/// The day that the available version was last checked
				int last_checked_day;
				/// The month that the available version was last checked
				int last_checked_month;
				/// The year that the available version was last checked
				int last_checked_year;
			}m_states;

			struct s_xml_source{
				/// The http address of the xml file
				char*			xml_address;

				GHTTPRequest	request_id;

				bool			request_get_attempted;
				bool			request_get_completed;
				bool			request_get_succeeded;
				PAD8;

				char*			data;
			}m_xml_sources[3];

			struct s_version{
				int32	m_major;
				int32	m_minor;
				int32	m_build;

				void SetBuild(const int major, const int minor, const int build)
				{
					m_major = major;
					m_minor = minor;
					m_build = build;
				}
			};
			/// The version of the current OS installation
			s_version m_current_version;
			/// The version of OS that is available online
			s_version m_available_version;
		public:
			virtual void	Initialize();
			virtual void	Dispose();

			void			LoadSettings(TiXmlElement* xml_element);
			void			SaveSettings(TiXmlElement* xml_element);

			virtual void	InitializeForNewMap() {}
			virtual void	Update(real delta_time);

		protected:
			void			LoadXmlServers(TiXmlElement* server_list);
			void			UpdateDateState();
			void			CheckForUpdates(bool do_blocking);
			void			ProcessVersionXml();
			virtual void	UpdateState();
		};
	}; };
};

#else

namespace Yelo
{
	namespace Networking { namespace VersionCheck
	{
		void		Initialize() {}
		void		Dispose() {}

#ifdef PLATFORM_IS_USER
		void		Initialize3D(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pParameters) {}
		void		OnLostDevice() {}
		void		OnResetDevice(D3DPRESENT_PARAMETERS* pParameters) {}
		void		Render() {}
		void		Release() {}
#endif

		void		LoadSettings(TiXmlElement* dx9_element) {}
		void		SaveSettings(TiXmlElement* dx9_element) {}

		void		InitializeForNewMap() {}
		void		Update(real delta_time) {}
	};};
};
#endif