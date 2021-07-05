USE [master]
GO
/****** Object:  Database [ManagementSystem]    Script Date: 7/5/2021 2:44:58 PM ******/
CREATE DATABASE [ManagementSystem]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'ManagementSystem', FILENAME = N'C:\Users\yistoyanova18\ManagementSystem.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'ManagementSystem_log', FILENAME = N'C:\Users\yistoyanova18\ManagementSystem_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
GO
IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [ManagementSystem].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO
ALTER DATABASE [ManagementSystem] SET ANSI_NULL_DEFAULT OFF 
GO
ALTER DATABASE [ManagementSystem] SET ANSI_NULLS OFF 
GO
ALTER DATABASE [ManagementSystem] SET ANSI_PADDING OFF 
GO
ALTER DATABASE [ManagementSystem] SET ANSI_WARNINGS OFF 
GO
ALTER DATABASE [ManagementSystem] SET ARITHABORT OFF 
GO
ALTER DATABASE [ManagementSystem] SET AUTO_CLOSE OFF 
GO
ALTER DATABASE [ManagementSystem] SET AUTO_SHRINK OFF 
GO
ALTER DATABASE [ManagementSystem] SET AUTO_UPDATE_STATISTICS ON 
GO
ALTER DATABASE [ManagementSystem] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO
ALTER DATABASE [ManagementSystem] SET CURSOR_DEFAULT  GLOBAL 
GO
ALTER DATABASE [ManagementSystem] SET CONCAT_NULL_YIELDS_NULL OFF 
GO
ALTER DATABASE [ManagementSystem] SET NUMERIC_ROUNDABORT OFF 
GO
ALTER DATABASE [ManagementSystem] SET QUOTED_IDENTIFIER OFF 
GO
ALTER DATABASE [ManagementSystem] SET RECURSIVE_TRIGGERS OFF 
GO
ALTER DATABASE [ManagementSystem] SET  DISABLE_BROKER 
GO
ALTER DATABASE [ManagementSystem] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO
ALTER DATABASE [ManagementSystem] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO
ALTER DATABASE [ManagementSystem] SET TRUSTWORTHY OFF 
GO
ALTER DATABASE [ManagementSystem] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO
ALTER DATABASE [ManagementSystem] SET PARAMETERIZATION SIMPLE 
GO
ALTER DATABASE [ManagementSystem] SET READ_COMMITTED_SNAPSHOT OFF 
GO
ALTER DATABASE [ManagementSystem] SET HONOR_BROKER_PRIORITY OFF 
GO
ALTER DATABASE [ManagementSystem] SET RECOVERY SIMPLE 
GO
ALTER DATABASE [ManagementSystem] SET  MULTI_USER 
GO
ALTER DATABASE [ManagementSystem] SET PAGE_VERIFY CHECKSUM  
GO
ALTER DATABASE [ManagementSystem] SET DB_CHAINING OFF 
GO
ALTER DATABASE [ManagementSystem] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO
ALTER DATABASE [ManagementSystem] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO
ALTER DATABASE [ManagementSystem] SET DELAYED_DURABILITY = DISABLED 
GO
USE [ManagementSystem]
GO
/****** Object:  Table [dbo].[User]    Script Date: 7/5/2021 2:44:58 PM ******/
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
	[IdOfTheCreator] [int] NOT NULL,
	[DateOfLastChange] [datetime] NOT NULL,
	[IdLastChange] [int] NOT NULL,
 CONSTRAINT [PK_User] PRIMARY KEY CLUSTERED 
(
	[Id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
USE [master]
GO
ALTER DATABASE [ManagementSystem] SET  READ_WRITE 
GO
