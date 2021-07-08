USE [master]
GO
/****** Object:  Database [ScaleFocus_Project]    Script Date: 8.7.2021 г. 18:06:07 ******/
CREATE DATABASE [ScaleFocus_Project]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'ScaleFocus_Project', FILENAME = N'D:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\ScaleFocus_Project.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'ScaleFocus_Project_log', FILENAME = N'D:\Program Files\Microsoft SQL Server\MSSQL15.SQLEXPRESS\MSSQL\DATA\ScaleFocus_Project_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [ScaleFocus_Project].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [ScaleFocus_Project] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET ARITHABORT OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [ScaleFocus_Project] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [ScaleFocus_Project] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET  DISABLE_BROKER 
GO
ALTER DATABASE [ScaleFocus_Project] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [ScaleFocus_Project] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [ScaleFocus_Project] SET  MULTI_USER 
GO
ALTER DATABASE [ScaleFocus_Project] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [ScaleFocus_Project] SET DB_CHAINING OFF 
GO
ALTER DATABASE [ScaleFocus_Project] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [ScaleFocus_Project] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [ScaleFocus_Project] SET DELAYED_DURABILITY = DISABLED 
GO
ALTER DATABASE [ScaleFocus_Project] SET QUERY_STORE = OFF
GO
USE [ScaleFocus_Project]
GO
/****** Object:  Table [dbo].[Project]    Script Date: 8.7.2021 г. 18:06:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Project](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Title] [nvarchar](50) NOT NULL,
	[Description] [nvarchar](50) NOT NULL,
	[DateOfCreation] [datetime] NULL,
	[IdCreator] [int] NOT NULL,
	[DateLastChange] [datetime] NULL,
	[IdLastChange] [int] NOT NULL,
 CONSTRAINT [PK_Project] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[ProjectTeam]    Script Date: 8.7.2021 г. 18:06:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[ProjectTeam](
	[IdOfProject] [int] NOT NULL,
	[IdOfTeam] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Task]    Script Date: 8.7.2021 г. 18:06:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Task](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[IdOfProject] [int] NOT NULL,
	[IdOfAssignee] [int] NOT NULL,
	[Title] [nvarchar](50) NOT NULL,
	[Description] [nvarchar](50) NOT NULL,
	[TaskStatus] [nvarchar](50) NOT NULL,
	[DateOfCreation] [datetime] NULL,
	[IdOfCreator] [int] NOT NULL,
	[DateLastChange] [datetime] NULL,
	[IdLastChange] [int] NOT NULL,
 CONSTRAINT [PK_Task] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Team]    Script Date: 8.7.2021 г. 18:06:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Team](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Title] [nvarchar](50) NOT NULL,
	[DateOfCreation] [datetime] NULL,
	[IdCreator] [int] NOT NULL,
	[DateLastChange] [datetime] NULL,
	[IdLastChange] [int] NOT NULL,
 CONSTRAINT [PK_Team] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[User]    Script Date: 8.7.2021 г. 18:06:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[User](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[Username] [nvarchar](50) NOT NULL,
	[Password] [nvarchar](50) NOT NULL,
	[FirstName] [nvarchar](50) NOT NULL,
	[LastName] [nvarchar](50) NOT NULL,
	[DateOfCreation] [datetime] NOT NULL,
	[IdOfCreator] [int] NULL,
	[DateLastChange] [datetime] NOT NULL,
	[IdLastChange] [int] NULL,
	[isAdmin] [bit] NULL,
 CONSTRAINT [PK_User] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[UserTeam]    Script Date: 8.7.2021 г. 18:06:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[UserTeam](
	[IdOfUser] [int] NOT NULL,
	[IdOfTeam] [int] NOT NULL
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[WorkLog]    Script Date: 8.7.2021 г. 18:06:07 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[WorkLog](
	[Id] [int] IDENTITY(1,1) NOT NULL,
	[IdTask] [int] NOT NULL,
	[IdUser] [int] NOT NULL,
	[Time] [int] NULL,
	[Date] [datetime] NULL,
 CONSTRAINT [PK_WorkLog] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET IDENTITY_INSERT [dbo].[Project] ON 
GO
INSERT [dbo].[Project] ([Id], [Title], [Description], [DateOfCreation], [IdCreator], [DateLastChange], [IdLastChange]) VALUES (1, N'Project1', N'Description1', CAST(N'2021-07-08T13:57:51.790' AS DateTime), 1, CAST(N'2021-07-08T13:57:51.790' AS DateTime), 1)
GO
INSERT [dbo].[Project] ([Id], [Title], [Description], [DateOfCreation], [IdCreator], [DateLastChange], [IdLastChange]) VALUES (2, N'Project2', N'Description2', CAST(N'2021-07-08T13:58:12.700' AS DateTime), 1, CAST(N'2021-07-08T13:58:12.700' AS DateTime), 2)
GO
SET IDENTITY_INSERT [dbo].[Project] OFF
GO
SET IDENTITY_INSERT [dbo].[Task] ON 
GO
INSERT [dbo].[Task] ([Id], [IdOfProject], [IdOfAssignee], [Title], [Description], [TaskStatus], [DateOfCreation], [IdOfCreator], [DateLastChange], [IdLastChange]) VALUES (2, 1, 2, N'Task1', N'Description1', N'InProgress', CAST(N'2021-07-08T14:22:15.747' AS DateTime), 1, CAST(N'2021-07-08T14:22:15.747' AS DateTime), 1)
GO
SET IDENTITY_INSERT [dbo].[Task] OFF
GO
SET IDENTITY_INSERT [dbo].[Team] ON 
GO
INSERT [dbo].[Team] ([Id], [Title], [DateOfCreation], [IdCreator], [DateLastChange], [IdLastChange]) VALUES (1, N'Team1', CAST(N'2021-07-08T13:44:58.603' AS DateTime), 1, CAST(N'2021-07-08T13:44:58.603' AS DateTime), 1)
GO
INSERT [dbo].[Team] ([Id], [Title], [DateOfCreation], [IdCreator], [DateLastChange], [IdLastChange]) VALUES (2, N'Team2', CAST(N'2021-07-08T13:45:20.513' AS DateTime), 1, CAST(N'2021-07-08T13:45:20.513' AS DateTime), 2)
GO
INSERT [dbo].[Team] ([Id], [Title], [DateOfCreation], [IdCreator], [DateLastChange], [IdLastChange]) VALUES (3, N'Team3', CAST(N'2021-07-08T13:45:36.290' AS DateTime), 2, CAST(N'2021-07-08T13:45:36.290' AS DateTime), 2)
GO
SET IDENTITY_INSERT [dbo].[Team] OFF
GO
SET IDENTITY_INSERT [dbo].[User] ON 
GO
INSERT [dbo].[User] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdOfCreator], [DateLastChange], [IdLastChange], [isAdmin]) VALUES (1, N'user1', N'userpass1', N'user1', N'user1', CAST(N'2021-07-07T10:51:24.250' AS DateTime), NULL, CAST(N'2021-07-08T16:12:10.167' AS DateTime), NULL, 1)
GO
INSERT [dbo].[User] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdOfCreator], [DateLastChange], [IdLastChange], [isAdmin]) VALUES (2, N'user2', N'userpass2', N'user2', N'user2', CAST(N'2021-07-07T11:02:36.300' AS DateTime), 1, CAST(N'2021-07-08T18:01:33.810' AS DateTime), 4, 0)
GO
INSERT [dbo].[User] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdOfCreator], [DateLastChange], [IdLastChange], [isAdmin]) VALUES (3, N'user3', N'userpass3', N'user3', N'user3', CAST(N'2021-07-07T11:04:33.673' AS DateTime), 1, CAST(N'2021-07-08T16:12:10.167' AS DateTime), 1, 0)
GO
INSERT [dbo].[User] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdOfCreator], [DateLastChange], [IdLastChange], [isAdmin]) VALUES (4, N'user4', N'userpass4', N'user4', N'user4', CAST(N'2021-07-08T15:47:06.877' AS DateTime), 1, CAST(N'2021-07-08T16:12:10.167' AS DateTime), 2, 0)
GO
INSERT [dbo].[User] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdOfCreator], [DateLastChange], [IdLastChange], [isAdmin]) VALUES (5, N'user5', N'userpass5', N'user5', N'user5', CAST(N'2021-07-08T15:49:00.733' AS DateTime), 2, CAST(N'2021-07-08T16:12:10.167' AS DateTime), 3, 0)
GO
INSERT [dbo].[User] ([Id], [Username], [Password], [FirstName], [LastName], [DateOfCreation], [IdOfCreator], [DateLastChange], [IdLastChange], [isAdmin]) VALUES (6, N'user6', N'userpass6', N'user6', N'user6', CAST(N'2021-07-08T17:58:12.437' AS DateTime), 2, CAST(N'2021-07-08T17:58:12.437' AS DateTime), 2, 0)
GO
SET IDENTITY_INSERT [dbo].[User] OFF
GO
SET IDENTITY_INSERT [dbo].[WorkLog] ON 
GO
INSERT [dbo].[WorkLog] ([Id], [IdTask], [IdUser], [Time], [Date]) VALUES (2, 2, 2, 3, CAST(N'2021-07-08T15:14:25.540' AS DateTime))
GO
SET IDENTITY_INSERT [dbo].[WorkLog] OFF
GO
ALTER TABLE [dbo].[Project] ADD  CONSTRAINT [DF_Project_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[Project] ADD  CONSTRAINT [DF_Project_DateLastChange]  DEFAULT (getdate()) FOR [DateLastChange]
GO
ALTER TABLE [dbo].[Task] ADD  CONSTRAINT [DF_Task_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[Task] ADD  CONSTRAINT [DF_Task_DateLastChange]  DEFAULT (getdate()) FOR [DateLastChange]
GO
ALTER TABLE [dbo].[Team] ADD  CONSTRAINT [DF_Team_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[Team] ADD  CONSTRAINT [DF_Team_DateLastChange]  DEFAULT (getdate()) FOR [DateLastChange]
GO
ALTER TABLE [dbo].[User] ADD  CONSTRAINT [DF_User_DateOfCreation]  DEFAULT (getdate()) FOR [DateOfCreation]
GO
ALTER TABLE [dbo].[User] ADD  CONSTRAINT [DF_User_DateOfLastChange]  DEFAULT (getdate()) FOR [DateLastChange]
GO
ALTER TABLE [dbo].[WorkLog] ADD  CONSTRAINT [DF_WorkLog_Date]  DEFAULT (getdate()) FOR [Date]
GO
ALTER TABLE [dbo].[Project]  WITH CHECK ADD  CONSTRAINT [FK_Project_User] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Project] CHECK CONSTRAINT [FK_Project_User]
GO
ALTER TABLE [dbo].[Project]  WITH CHECK ADD  CONSTRAINT [FK_Project_User1] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Project] CHECK CONSTRAINT [FK_Project_User1]
GO
ALTER TABLE [dbo].[Project]  WITH CHECK ADD  CONSTRAINT [FK_Project_User2] FOREIGN KEY([IdLastChange])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Project] CHECK CONSTRAINT [FK_Project_User2]
GO
ALTER TABLE [dbo].[ProjectTeam]  WITH CHECK ADD  CONSTRAINT [FK_ProjectTeam_Project] FOREIGN KEY([IdOfProject])
REFERENCES [dbo].[Project] ([Id])
GO
ALTER TABLE [dbo].[ProjectTeam] CHECK CONSTRAINT [FK_ProjectTeam_Project]
GO
ALTER TABLE [dbo].[ProjectTeam]  WITH CHECK ADD  CONSTRAINT [FK_ProjectTeam_Team] FOREIGN KEY([IdOfTeam])
REFERENCES [dbo].[Team] ([Id])
GO
ALTER TABLE [dbo].[ProjectTeam] CHECK CONSTRAINT [FK_ProjectTeam_Team]
GO
ALTER TABLE [dbo].[Task]  WITH CHECK ADD  CONSTRAINT [FK_Task_Project] FOREIGN KEY([IdOfProject])
REFERENCES [dbo].[Project] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[Task] CHECK CONSTRAINT [FK_Task_Project]
GO
ALTER TABLE [dbo].[Task]  WITH CHECK ADD  CONSTRAINT [FK_Task_User] FOREIGN KEY([IdOfAssignee])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Task] CHECK CONSTRAINT [FK_Task_User]
GO
ALTER TABLE [dbo].[Task]  WITH CHECK ADD  CONSTRAINT [FK_Task_User1] FOREIGN KEY([IdOfCreator])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Task] CHECK CONSTRAINT [FK_Task_User1]
GO
ALTER TABLE [dbo].[Team]  WITH CHECK ADD  CONSTRAINT [FK_Team_User] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Team] CHECK CONSTRAINT [FK_Team_User]
GO
ALTER TABLE [dbo].[Team]  WITH CHECK ADD  CONSTRAINT [FK_Team_User1] FOREIGN KEY([IdCreator])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Team] CHECK CONSTRAINT [FK_Team_User1]
GO
ALTER TABLE [dbo].[Team]  WITH CHECK ADD  CONSTRAINT [FK_Team_User2] FOREIGN KEY([IdLastChange])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[Team] CHECK CONSTRAINT [FK_Team_User2]
GO
ALTER TABLE [dbo].[User]  WITH CHECK ADD  CONSTRAINT [FK_User_User] FOREIGN KEY([IdOfCreator])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[User] CHECK CONSTRAINT [FK_User_User]
GO
ALTER TABLE [dbo].[User]  WITH CHECK ADD  CONSTRAINT [FK_User_User1] FOREIGN KEY([IdLastChange])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[User] CHECK CONSTRAINT [FK_User_User1]
GO
ALTER TABLE [dbo].[UserTeam]  WITH CHECK ADD  CONSTRAINT [FK_UserTeam_Team] FOREIGN KEY([IdOfTeam])
REFERENCES [dbo].[Team] ([Id])
GO
ALTER TABLE [dbo].[UserTeam] CHECK CONSTRAINT [FK_UserTeam_Team]
GO
ALTER TABLE [dbo].[UserTeam]  WITH CHECK ADD  CONSTRAINT [FK_UserTeam_User] FOREIGN KEY([IdOfUser])
REFERENCES [dbo].[User] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[UserTeam] CHECK CONSTRAINT [FK_UserTeam_User]
GO
ALTER TABLE [dbo].[WorkLog]  WITH CHECK ADD  CONSTRAINT [FK_WorkLog_Task] FOREIGN KEY([IdTask])
REFERENCES [dbo].[Task] ([Id])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[WorkLog] CHECK CONSTRAINT [FK_WorkLog_Task]
GO
ALTER TABLE [dbo].[WorkLog]  WITH CHECK ADD  CONSTRAINT [FK_WorkLog_User] FOREIGN KEY([IdUser])
REFERENCES [dbo].[User] ([Id])
GO
ALTER TABLE [dbo].[WorkLog] CHECK CONSTRAINT [FK_WorkLog_User]
GO
ALTER TABLE [dbo].[Task]  WITH CHECK ADD  CONSTRAINT [CK_Task] CHECK  (([TaskStatus]='Pending' OR [TaskStatus]='InProgress' OR [TaskStatus]='Completed'))
GO
ALTER TABLE [dbo].[Task] CHECK CONSTRAINT [CK_Task]
GO
USE [master]
GO
ALTER DATABASE [ScaleFocus_Project] SET  READ_WRITE 
GO
