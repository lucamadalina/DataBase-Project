-- --------------------------------------------------------
-- Server:                       127.0.0.1
-- Versiune server:              5.7.21-log - MySQL Community Server (GPL)
-- SO server:                    Win64
-- HeidiSQL Versiune:            9.5.0.5196
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Descarcă structura bazei de date pentru hlrhwruh
CREATE DATABASE IF NOT EXISTS `hlrhwruh` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `hlrhwruh`;

-- Descarcă structura pentru tabelă hlrhwruh.categorie_gen
CREATE TABLE IF NOT EXISTS `categorie_gen` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `gen` varchar(50) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
-- Descarcă structura pentru tabelă hlrhwruh.categorie_greutate
CREATE TABLE IF NOT EXISTS `categorie_greutate` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `prag_min` int(11) DEFAULT NULL,
  `prag_max` int(11) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
-- Descarcă structura pentru tabelă hlrhwruh.categorie_varsta
CREATE TABLE IF NOT EXISTS `categorie_varsta` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `prag_min` int(11) DEFAULT NULL,
  `prag_max` int(11) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
-- Descarcă structura pentru tabelă hlrhwruh.clasament_organizatii
CREATE TABLE IF NOT EXISTS `clasament_organizatii` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_organizatie` int(11) DEFAULT NULL,
  `numar_puncte` int(11) DEFAULT NULL,
  KEY `id` (`id`),
  KEY `FK_clasament_organizatii_club_sportiv` (`id_organizatie`),
  CONSTRAINT `FK_clasament_organizatii_club_sportiv` FOREIGN KEY (`id_organizatie`) REFERENCES `club_sportiv` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
-- Descarcă structura pentru tabelă hlrhwruh.clasament_sportiv
CREATE TABLE IF NOT EXISTS `clasament_sportiv` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_sportiv` int(11) DEFAULT NULL,
  `id_categorie_greutate` int(11) DEFAULT NULL,
  `id_categorie_varsta` int(11) DEFAULT NULL,
  `id_categorie_gen` int(11) DEFAULT NULL,
  `numar_puncte` int(11) DEFAULT NULL,
  KEY `id` (`id`),
  KEY `FK_clasament_sportiv_sportiv` (`id_sportiv`),
  KEY `FK_clasament_sportiv_categorie_greutate` (`id_categorie_greutate`),
  KEY `FK_clasament_sportiv_categorie_varsta` (`id_categorie_varsta`),
  KEY `FK_clasament_sportiv_categorie_gen` (`id_categorie_gen`),
  CONSTRAINT `FK_clasament_sportiv_categorie_gen` FOREIGN KEY (`id_categorie_gen`) REFERENCES `categorie_gen` (`id`),
  CONSTRAINT `FK_clasament_sportiv_categorie_greutate` FOREIGN KEY (`id_categorie_greutate`) REFERENCES `categorie_greutate` (`id`),
  CONSTRAINT `FK_clasament_sportiv_categorie_varsta` FOREIGN KEY (`id_categorie_varsta`) REFERENCES `categorie_varsta` (`id`),
  CONSTRAINT `FK_clasament_sportiv_sportiv` FOREIGN KEY (`id_sportiv`) REFERENCES `sportiv` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
-- Descarcă structura pentru tabelă hlrhwruh.club_sportiv
CREATE TABLE IF NOT EXISTS `club_sportiv` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `denumire` varchar(50) DEFAULT NULL,
  `tara` varchar(50) DEFAULT NULL,
  `adresa` varchar(50) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
-- Descarcă structura pentru tabelă hlrhwruh.competitie
CREATE TABLE IF NOT EXISTS `competitie` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `denumire` varchar(50) DEFAULT NULL,
  `puncte_participare` int(11) NOT NULL,
  `locatie` varchar(50) DEFAULT NULL,
  `puncte_runda1` int(11) DEFAULT NULL,
  `puncte_semifinala` int(11) DEFAULT NULL,
  `puncte_finala` int(11) DEFAULT NULL,
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
-- Descarcă structura pentru tabelă hlrhwruh.sportiv
CREATE TABLE IF NOT EXISTS `sportiv` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nume` varchar(50) DEFAULT NULL,
  `prenume` varchar(50) DEFAULT NULL,
  `varsta` int(11) DEFAULT NULL,
  `greutate` int(11) DEFAULT NULL,
  `tara` varchar(50) DEFAULT NULL,
  `gen` varchar(50) DEFAULT NULL,
  `id_club` int(11) DEFAULT NULL,
  `id_categorie_greutate` int(11) DEFAULT NULL,
  `id_categorie_varsta` int(11) DEFAULT NULL,
  `id_categorie_gen` int(11) DEFAULT NULL,
  KEY `id` (`id`),
  KEY `FK_sportiv_club_sportiv` (`id_club`),
  KEY `FK_sportiv_categorie_greutate` (`id_categorie_greutate`),
  KEY `FK_sportiv_categorie_varsta` (`id_categorie_varsta`),
  KEY `FK_sportiv_categorie_gen` (`id_categorie_gen`),
  CONSTRAINT `FK_sportiv_categorie_gen` FOREIGN KEY (`id_categorie_gen`) REFERENCES `categorie_gen` (`id`),
  CONSTRAINT `FK_sportiv_categorie_greutate` FOREIGN KEY (`id_categorie_greutate`) REFERENCES `categorie_greutate` (`id`),
  CONSTRAINT `FK_sportiv_categorie_varsta` FOREIGN KEY (`id_categorie_varsta`) REFERENCES `categorie_varsta` (`id`),
  CONSTRAINT `FK_sportiv_club_sportiv` FOREIGN KEY (`id_club`) REFERENCES `club_sportiv` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- Exportarea datelor nu a fost selectată.
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
